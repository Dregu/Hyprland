#include "SizeMatchEngine.hpp"
#include <hyprutils/math/Vector2D.hpp>
#include "../../../debug/log/Logger.hpp"

#include <sstream>

using namespace Desktop::Rule;

CSizeMatchEngine::CSizeMatchEngine(const std::string& s) {
    std::istringstream ss(s);
    int                x, y;
    if (ss >> x >> y)
        m_value = {x, y};
    else
        Log::logger->log(Log::ERR, "CSizeMatchEngine: invalid input {}", s);
}

bool CSizeMatchEngine::match(Hyprutils::Math::Vector2D other) {
    return m_value == other || (m_value.x == -1 && m_value.y == -1) || (m_value.x == -1 && m_value.y == other.y) || (m_value.y == -1 && m_value.x == other.x);
}
