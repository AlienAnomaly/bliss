#include "level.h"

#include <fstream>
#include <utility>
#include <iostream>
#include <stdexcept>

namespace bliss
{
    LevelClass::LevelClass(std::string p_LevelName, std::string p_LevelConfigPath)
        : m_LevelName(std::move(p_LevelName))
        , m_LevelConfigPath(std::move(p_LevelConfigPath))
    {
        std::ifstream ifs(m_LevelConfigPath);
        if (!ifs.is_open())
            throw std::runtime_error("Error opening file");

        m_LevelConfigData = json::parse(ifs);
        ifs.close();

        m_WorldData = m_LevelConfigData["WORLD"].get<std::vector<int>>();
        m_EntityData = m_LevelConfigData["ENTITY-DATA"].get<std::vector<int>>();
    }

    const std::string& LevelClass::GetLevelName() const
    {
        return m_LevelName;
    }

    const std::string& LevelClass::GetLevelConfigPath() const
    {
        return m_LevelConfigPath;
    }
}