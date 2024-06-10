// Macro to make the constraints that items that can be used to decorate must adhere to 
#define DECORATOR_CONSTRAINT(name, ret_type) \
    { a.name() } -> std::same_as<ret_type>;

// Macro to make a decorator
#define MAKE_DECORATOR(name, ...) \
template <typename T> \
concept name = requires(T a) { \
    __VA_ARGS__ \
};

