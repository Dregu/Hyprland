#pragma once

#include "../../DesktopTypes.hpp"
#include <hyprutils/math/Vector2D.hpp>

class CTagKeeper;

namespace Desktop::Rule {
    enum eRuleMatchEngine : uint8_t {
        RULE_MATCH_ENGINE_REGEX = 0,
        RULE_MATCH_ENGINE_BOOL,
        RULE_MATCH_ENGINE_INT,
        RULE_MATCH_ENGINE_WORKSPACE,
        RULE_MATCH_ENGINE_TAG,
        RULE_MATCH_ENGINE_SIZE,
    };

    class IMatchEngine {
      public:
        virtual ~IMatchEngine() = default;
        virtual bool match(const std::string&);
        virtual bool match(bool);
        virtual bool match(int);
        virtual bool match(PHLWORKSPACE);
        virtual bool match(const CTagKeeper& keeper);
        virtual bool match(Hyprutils::Math::Vector2D);

      protected:
        IMatchEngine() = default;
    };
};