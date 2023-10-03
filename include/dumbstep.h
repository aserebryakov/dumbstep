#pragma once
#include <functional>


class DumbStep {
    public:
        DumbStep step(std::function<bool()> f) {
            if (!f()) {
                _success = false;
            }

            return DumbStep{};
        }

        bool success() const {
            return _success;
        }

    private:
        bool _success{true};
};
