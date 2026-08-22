#pragma once

#include "MatchEngine.hpp"
#include <hyprutils/math/Vector2D.hpp>

namespace Desktop::Rule {
    class CSizeMatchEngine : public IMatchEngine {
      public:
        CSizeMatchEngine(const std::string&);
        virtual ~CSizeMatchEngine() = default;

        virtual bool match(Hyprutils::Math::Vector2D other);

      private:
        Hyprutils::Math::Vector2D m_value = {-1, -1};
    };
}
