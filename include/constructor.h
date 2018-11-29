struct X {
    X() { throw std::runtime_error(""); }

    void* operator new(std::size_t sz, bool b) {
        std::cout << "custom new called, b = " << b << std::endl;
        return std::malloc(sz);
    }

    void operator delete(void* ptr, bool b) {
        std::cout << "custom delete called, b = " << b << std::endl;
        std::free(ptr);
    }
};

