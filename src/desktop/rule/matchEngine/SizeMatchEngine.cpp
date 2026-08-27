#include "SizeMatchEngine.hpp"
#include <hyprutils/math/Vector2D.hpp>
#include "../../../debug/log/Logger.hpp"

#include <sstream>

using namespace Desktop::Rule;

CSizeMatchEngine::CSizeMatchEngine(const std::string& s) {
    std::string text(s);
    std::ranges::replace_if(text, [](unsigned char c) { return !std::isdigit(c); }, ' ');
    std::istringstream ss(text);
    int                x = -1;
    int                y = -1;
    ss >> x >> y;
    m_value = {x, y};
}

bool CSizeMatchEngine::match(Hyprutils::Math::Vector2D other) {
    return m_value == other || (m_value.x == -1 && m_value.y == -1) || (m_value.x == -1 && m_value.y == other.y) || (m_value.y == -1 && m_value.x == other.x);
}
