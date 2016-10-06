/// \file
// Range v3 library
//
// Copyright Eric Niebler 2014
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/ericniebler/range-v3
//
#ifndef RANGES_V3_VIEW_ADAPTOR_HPP
#define RANGES_V3_VIEW_ADAPTOR_HPP

#include <meta/meta.hpp>
#include <range/v3/range_fwd.hpp>
#include <range/v3/size.hpp>
#include <range/v3/distance.hpp>
#include <range/v3/view_facade.hpp>
#include <range/v3/range_traits.hpp>
#include <range/v3/utility/concepts.hpp>
#include <range/v3/utility/iterator_concepts.hpp>
#include <range/v3/utility/iterator_traits.hpp>
#include <range/v3/view/all.hpp>

namespace ranges
{
    inline namespace v3
    {
        /// \cond
        namespace detail
        {
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_ALIAS_DECLTYPE
            template <typename T>
            using begin_adaptor_t_void_t = void;
            template <class T, class V = void> struct begin_adaptor_t_helper {};
            template <class T> struct begin_adaptor_t_helper<T, begin_adaptor_t_void_t<decltype(range_access::begin_adaptor(std::declval<T &>(), 42))>> {
                typedef decltype(range_access::begin_adaptor(std::declval<T &>(), 42)) type;
            };
            template<typename T>
            using begin_adaptor_t = typename begin_adaptor_t_helper<T>::type;

            template <typename T>
            using end_adaptor_t_void_t = void;
            template <class T, class V = void> struct end_adaptor_t_helper {};
            template <class T> struct end_adaptor_t_helper<T, end_adaptor_t_void_t<decltype(range_access::end_adaptor(std::declval<T &>(), 42))>> {
                typedef decltype(range_access::end_adaptor(std::declval<T &>(), 42)) type;
            };
            template<typename T>
            using end_adaptor_t = typename end_adaptor_t_helper<T>::type;

            template <typename T>
            using adapted_iterator_t_void_t = void;
            template <class T, class V = void> struct adapted_iterator_t_helper {};
            template <class T> struct adapted_iterator_t_helper<T, adapted_iterator_t_void_t<decltype(std::declval<begin_adaptor_t<T>>().begin(std::declval<T &>()))>> {
                typedef decltype(std::declval<begin_adaptor_t<T>>().begin(std::declval<T &>())) type;
            };
            template<typename T>
            using adapted_iterator_t = typename adapted_iterator_t_helper<T>::type;

            template <typename T>
            using adapted_sentinel_t_void_t = void;
            template <class T, class V = void> struct adapted_sentinel_t_helper {};
            template <class T> struct adapted_sentinel_t_helper<T, adapted_sentinel_t_void_t<decltype(std::declval<end_adaptor_t<T>>().end(std::declval<T &>()))>> {
                typedef decltype(std::declval<end_adaptor_t<T>>().end(std::declval<T &>())) type;
            };
            template<typename T>
            using adapted_sentinel_t = typename adapted_sentinel_t_helper<T>::type;
#else
            template<typename Derived>
            using begin_adaptor_t =
                decltype(range_access::begin_adaptor(std::declval<Derived &>(), 42));

            template<typename Derived>
            using end_adaptor_t =
                decltype(range_access::end_adaptor(std::declval<Derived &>(), 42));

            template<typename Derived>
            using adapted_iterator_t =
                decltype(std::declval<begin_adaptor_t<Derived>>().begin(std::declval<Derived &>()));

            template<typename Derived>
            using adapted_sentinel_t =
                decltype(std::declval<end_adaptor_t<Derived>>().end(std::declval<Derived &>()));
#endif

            struct adaptor_base_current_mem_fn
            {};

            template<typename BaseIter, typename Adapt, typename Enable = void>
            struct adaptor_value_type2
            {};

            template<typename BaseIter, typename Adapt>
            struct adaptor_value_type2<
                BaseIter,
                Adapt,
                meta::void_<decltype(Adapt::current(BaseIter{}, adaptor_base_current_mem_fn{}))>>
            {
                using value_type = iterator_value_t<BaseIter>;
            };

            template<typename BaseIter, typename Adapt, typename Enable = void>
            struct adaptor_value_type
              : adaptor_value_type2<BaseIter, Adapt>
            {};

            template<typename BaseIter, typename Adapt>
            struct adaptor_value_type<BaseIter, Adapt, meta::void_<typename Adapt::value_type>>
            {
                using value_type = typename Adapt::value_type;
            };
        }
        /// \endcond

        /// \addtogroup group-core
        /// @{
        template<typename Derived>
        using base_range_t = meta::_t<range_access::base_range<Derived>>;

        template<typename Derived>
        using view_adaptor_t = meta::_t<range_access::view_adaptor<Derived>>;

#if defined(RANGES_WORKAROUND_MSVC_PERMISSIVE_HIDDEN_FRIEND) || defined(RANGES_WORKAROUND_MSVC_INDIRECT_MOVE)
        namespace adaptor_cursor_detail
        {
#endif
        template<typename BaseIt, typename Adapt>
        struct adaptor_cursor;
#if defined(RANGES_WORKAROUND_MSVC_PERMISSIVE_HIDDEN_FRIEND) || defined(RANGES_WORKAROUND_MSVC_INDIRECT_MOVE)
        }
        using adaptor_cursor_detail::adaptor_cursor;
#endif

        template<typename BaseSent, typename Adapt>
        struct adaptor_sentinel;

        struct adaptor_base
        {
            adaptor_base() = default;
            adaptor_base(adaptor_base &&) = default;
            adaptor_base(adaptor_base const &) = default;
            adaptor_base &operator=(adaptor_base &&) = default;
            adaptor_base &operator=(adaptor_base const &) = default;

            adaptor_base(detail::any, detail::any = {}, detail::any = {})
            {}
            template<typename Rng>
            range_iterator_t<base_range_t<Rng>> begin(Rng &rng) const
            {
                return ranges::begin(rng.base());
            }
            template<typename Rng>
            range_sentinel_t<base_range_t<Rng>> end(Rng &rng) const
            {
                return ranges::end(rng.base());
            }
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename I, CONCEPT_REQUIRES_(Iterator<I>::value)>
#else
            template<typename I, CONCEPT_REQUIRES_(Iterator<I>())>
#endif
            static bool equal(I const &it0, I const &it1)
            {
                return it0 == it1;
            }
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename I, CONCEPT_REQUIRES_(WeakIterator<I>::value)>
#else
            template<typename I, CONCEPT_REQUIRES_(WeakIterator<I>())>
#endif
            static iterator_reference_t<I> current(I const &it, detail::adaptor_base_current_mem_fn = {})
                noexcept(noexcept(iterator_reference_t<I>(*it)))
            {
                return *it;
            }
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename I, CONCEPT_REQUIRES_(WeakIterator<I>::value)>
#else
            template<typename I, CONCEPT_REQUIRES_(WeakIterator<I>())>
#endif
            static void next(I &it)
            {
                ++it;
            }
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename I, CONCEPT_REQUIRES_(BidirectionalIterator<I>::value)>
#else
            template<typename I, CONCEPT_REQUIRES_(BidirectionalIterator<I>())>
#endif
            static void prev(I &it)
            {
                --it;
            }
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename I, CONCEPT_REQUIRES_(RandomAccessIterator<I>::value)>
#else
            template<typename I, CONCEPT_REQUIRES_(RandomAccessIterator<I>())>
#endif
            static void advance(I &it, iterator_difference_t<I> n)
            {
                it += n;
            }
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename I, CONCEPT_REQUIRES_(RandomAccessIterator<I>::value)>
#else
            template<typename I, CONCEPT_REQUIRES_(RandomAccessIterator<I>())>
#endif
            static iterator_difference_t<I> distance_to(I const &it0, I const &it1)
            {
                return it1 - it0;
            }
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename I, typename S, CONCEPT_REQUIRES_(IteratorRange<I, S>::value)>
#else
            template<typename I, typename S, CONCEPT_REQUIRES_(IteratorRange<I, S>())>
#endif
            static constexpr bool empty(I const &it, S const &end)
            {
                return it == end;
            }
        };

#if defined(RANGES_WORKAROUND_MSVC_PERMISSIVE_HIDDEN_FRIEND) || defined(RANGES_WORKAROUND_MSVC_INDIRECT_MOVE)
        namespace adaptor_cursor_detail
        {
#endif
        // Build a cursor out of an iterator into the adapted range, and an
        // adaptor that customizes behavior.
        template<typename BaseIter, typename Adapt>
        struct RANGES_BROKEN_EBO adaptor_cursor
          : private compressed_pair<BaseIter, Adapt>
          , detail::adaptor_value_type<BaseIter, Adapt>
        {
            using single_pass = meta::or_<
                range_access::single_pass_t<Adapt>,
                SinglePass<BaseIter>>;
            using compressed_pair<BaseIter, Adapt>::compressed_pair;
            struct mixin : basic_mixin<adaptor_cursor>
            {
                using basic_mixin<adaptor_cursor>::basic_mixin;
                // All iterators into adapted ranges have a base() member for fetching
                // the underlying iterator.
                BaseIter base() const
                {
                    return this->get().first;
                }
            };
        private:
            template<typename BaseSent, typename SentAdapt>
            friend struct adaptor_sentinel;
            using compressed_pair<BaseIter, Adapt>::first;
            using compressed_pair<BaseIter, Adapt>::second;
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().equal(first, first, second))>
            bool equal_(adaptor_cursor const &that, int) const
            {
                return second.equal(first, that.first, that.second);
            }
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().equal(first, first))>
            bool equal_(adaptor_cursor const &that, long) const
            {
                return second.equal(first, that.first);
            }
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().distance_to(first, first, second))>
            R distance_to_(adaptor_cursor const &that, int) const
            {
                return second.distance_to(first, that.first, that.second);
            }
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().distance_to(first, first))>
            R distance_to_(adaptor_cursor const &that, long) const
            {
                return second.distance_to(first, that.first);
            }
            // If the adaptor has an indirect_move function, use it.
            template<typename A = Adapt,
                typename X = decltype(std::declval<A>().indirect_move(first))>
            X indirect_move_(int) const
                noexcept(noexcept(std::declval<A>().indirect_move(first)))
            {
                using V = range_access::cursor_value_t<adaptor_cursor>;
                using R = decltype(std::declval<A>().current(first));
                static_assert(
                    CommonReference<X &&, V const &>(),
                    "In your adaptor, the result of your indirect_move member function does "
                    "not share a common reference with your value type.");
                static_assert(
                    CommonReference<R &&, X &&>(),
                    "In your adaptor, the result of your indirect_move member function does "
                    "not share a common reference with the result of your current member "
                    "function.");
                return second.indirect_move(first);
            }
            // If there is no indirect_move member and the adaptor has not overridden the current
            // member function, then dispatch to the base iterator's indirect_move function.
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().current(first, detail::adaptor_base_current_mem_fn{})),
                typename X = iterator_rvalue_reference_t<BaseIter>>
            X indirect_move_(long) const
#ifndef RANGES_WORKAROUND_MSVC_211850
                // FIXME: *not* a workaround; disables a feature.
                noexcept(noexcept(X(ranges::indirect_move(first))))
#endif
            {
                return ranges::indirect_move(first);
            }
            // If the adaptor does not have an indirect_move function but overrides the current
            // member function, apply std::move to the result of calling current.
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().current(first)),
                typename X =
                    meta::if_<std::is_reference<R>, meta::_t<std::remove_reference<R>> &&, R>>
            X indirect_move_(detail::any) const
                noexcept(noexcept(X(static_cast<X &&>(std::declval<R>()))))
            {
                using V = range_access::cursor_value_t<adaptor_cursor>;
                static_assert(
                    CommonReference<X &&, V const &>(),
                    "In your adaptor, you've specified a value type that does not "
                    "share a common reference type with the result of moving the value "
                    "returned by current. Consider defining an indirect_move function "
                    "in your adaptor.");
                return static_cast<X &&>(second.current(first));
            }
            // Gives users a way to override the default indirect_move function in their adaptors.
            template<typename Sent>
            friend auto indirect_move(basic_iterator<adaptor_cursor, Sent> const &it)
            RANGES_DECLTYPE_AUTO_RETURN_NOEXCEPT
            (
                get_cursor(it).indirect_move_(42)
            )
        public:
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().current(first))>
            R current() const
                noexcept(noexcept(R(std::declval<A>().current(first))))
            {
                using V = range_access::cursor_value_t<adaptor_cursor>;
                static_assert(
                    CommonReference<R &&, V &>(),
                    "In your adaptor, you've specified a value type that does not "
                    "share a common reference type with the return type of current.");
                return second.current(first);
            }
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().next(first))>
            void next()
            {
                second.next(first);
            }
            template<typename C = adaptor_cursor>
            auto equal(adaptor_cursor const &that) const ->
                decltype(std::declval<C const &>().equal_(that, 42))
            {
                return this->equal_(that, 42);
            }
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().prev(first))>
            void prev()
            {
                second.prev(first);
            }
            template<typename A = Adapt,
                typename R = decltype(std::declval<A>().advance(first, 0))>
            void advance(iterator_difference_t<BaseIter> n)
            {
                second.advance(first, n);
            }
            template<typename C = adaptor_cursor>
            auto distance_to(adaptor_cursor const &that) const ->
                decltype(std::declval<C const &>().distance_to_(that, 42))
            {
                return this->distance_to_(that, 42);
            }
        };
#if defined(RANGES_WORKAROUND_MSVC_PERMISSIVE_HIDDEN_FRIEND) || defined(RANGES_WORKAROUND_MSVC_INDIRECT_MOVE)
        }
#endif

        // Build a sentinel out of a sentinel into the adapted range, and an
        // adaptor that customizes behavior.
        template<typename BaseSent, typename Adapt>
        struct adaptor_sentinel
          : private compressed_pair<BaseSent, Adapt>
        {
            using single_pass = range_access::single_pass_t<Adapt>;
            using compressed_pair<BaseSent, Adapt>::compressed_pair;
        private:
            using compressed_pair<BaseSent, Adapt>::first;
            using compressed_pair<BaseSent, Adapt>::second;
            template<typename I, typename IA, typename A = Adapt,
                typename R = decltype(std::declval<A>().empty(std::declval<I>(), std::declval<IA>(), first))>
            constexpr bool equal_(adaptor_cursor<I, IA> const &that, int) const
            {
                return second.empty(that.first, that.second, first);
            }
            template<typename I, typename IA, typename A = Adapt,
                typename R = decltype(std::declval<A>().empty(std::declval<I>(), first))>
            constexpr bool equal_(adaptor_cursor<I, IA> const &that, long) const
            {
                return second.empty(that.first, first);
            }
        public:
            struct mixin
              : basic_mixin<adaptor_sentinel>
            {
                using basic_mixin<adaptor_sentinel>::basic_mixin;
                // All iterators into adapted ranges have a base() member for fetching
                // the underlying iterator.
                BaseSent base() const
                {
                    return this->get().first;
                }
            };
            template<typename I, typename IA, typename S = adaptor_sentinel>
            constexpr auto equal(adaptor_cursor<I, IA> const &that) const ->
                decltype(std::declval<S const &>().equal_(that, 42))
            {
                return this->equal_(that, 42);
            }
        };

        template<typename D>
        using adaptor_cursor_t =
            adaptor_cursor<detail::adapted_iterator_t<D>, detail::begin_adaptor_t<D>>;

        template<typename D>
        using adaptor_sentinel_t =
            meta::if_<
                meta::and_<
                    Same<detail::adapted_iterator_t<D>, detail::adapted_sentinel_t<D>>,
                    Same<detail::begin_adaptor_t<D>, detail::end_adaptor_t<D>>>,
                adaptor_cursor<detail::adapted_iterator_t<D>, detail::begin_adaptor_t<D>>,
                adaptor_sentinel<detail::adapted_sentinel_t<D>, detail::end_adaptor_t<D>>>;

        template<typename Derived, typename BaseRng, cardinality Cardinality /*= range_cardinality<BaseRng>::value*/>
        struct view_adaptor
          : view_facade<Derived, Cardinality>
        {
        private:
            friend Derived;
            friend range_access;
            friend adaptor_base;
            using view_adaptor_t = view_adaptor;
            using base_range_t = view::all_t<BaseRng>;
            using view_facade<Derived, Cardinality>::derived;
            // Mutable here. Const-correctness is enforced below by disabling
            // begin_cursor/end_cursor if "BaseRng const" does not model
            // the View concept.
            mutable base_range_t rng_;

            base_range_t & mutable_base() const
            {
                return rng_;
            }
            adaptor_base begin_adaptor() const
            {
                return {};
            }
            adaptor_base end_adaptor() const
            {
                return {};
            }

#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename D = Derived, CONCEPT_REQUIRES_(Same<D, Derived>::value)>
#else
            template<typename D = Derived, CONCEPT_REQUIRES_(Same<D, Derived>())>
#endif
            adaptor_cursor_t<D> begin_cursor()
            {
                auto adapt = range_access::begin_adaptor(derived(), 42);
                auto pos = adapt.begin(derived());
                return {std::move(pos), std::move(adapt)};
            }
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
            template<typename D = Derived, CONCEPT_REQUIRES_(Same<D, Derived>::value)>
#else
            template<typename D = Derived, CONCEPT_REQUIRES_(Same<D, Derived>())>
#endif
            adaptor_sentinel_t<D> end_cursor()
            {
                auto adapt = range_access::end_adaptor(derived(), 42);
                auto pos = adapt.end(derived());
                return {std::move(pos), std::move(adapt)};
            }
            // Const-correctness is enforced here by only allowing these if the base range
            // has const begin/end accessors. That disables the const begin()/end() accessors
            // in view_facade, meaning the derived range type only has mutable iterators.
            template<typename D = Derived,
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
                CONCEPT_REQUIRES_(Same<D, Derived>::value && View<base_range_t const>::value)>
#else
                CONCEPT_REQUIRES_(Same<D, Derived>() && View<base_range_t const>())>
#endif
            adaptor_cursor_t<D const> begin_cursor() const
            {
                auto adapt = range_access::begin_adaptor(derived(), 42);
                auto pos = adapt.begin(derived());
                return {std::move(pos), std::move(adapt)};
            }
            template<typename D = Derived,
#ifdef RANGES_WORKAROUND_MSVC_SFINAE_CONSTEXPR
                CONCEPT_REQUIRES_(Same<D, Derived>::value && View<base_range_t const>::value)>
#else
                CONCEPT_REQUIRES_(Same<D, Derived>() && View<base_range_t const>())>
#endif
            adaptor_sentinel_t<D const> end_cursor() const
            {
                auto adapt = range_access::end_adaptor(derived(), 42);
                auto pos = adapt.end(derived());
                return {std::move(pos), std::move(adapt)};
            }
        public:
            view_adaptor() = default;
            constexpr view_adaptor(BaseRng && rng)
              : rng_(view::all(detail::forward<BaseRng>(rng)))
            {}
            base_range_t & base()
            {
                return rng_;
            }
            /// \overload
            base_range_t const & base() const
            {
                return rng_;
            }
        };

        /// @}
    }
}

#endif
