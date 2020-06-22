#pragma once

template<typename func>
struct __defer_struct {
    func const& __f;
    __defer_struct(func const& g) : __f(g) { }
    ~__defer_struct() { __f(); }
};

#define __defer_helper(code, count)                         \
auto __defer_func_##count = [&]() { code; };                \
__defer_struct __defer_object_##count(__defer_func_##count)

#define __defer_ind(code, count) __defer_helper(code, count)

#define defer(code, ...) __defer_ind(code, __COUNTER__)