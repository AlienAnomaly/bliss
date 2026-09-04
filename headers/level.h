#pragma once

#include <string>

#include "json.hpp"

namespace bliss
{
    using json = nlohmann::json;

    class LevelClass
    {
    public:
        LevelClass(std::string p_LevelName, std::string p_LevelConfigPath);
        ~LevelClass() = default;

    private:
        const std::string m_LevelName;
        const std::string m_LevelConfigPath;
        json m_LevelConfigData;

        // ============ Level Data ============ //

        // tilemaps etc.
        std::vector<int> m_WorldData;

        // different types of entities denoted by enums
        std::vector<int> m_EntityData;
        std::vector<int[2]> m_EntitySpawnData;

        // ==================================== //

    public:
        [[nodiscard]] const std::string& GetLevelName() const;
        [[nodiscard]] const std::string& GetLevelConfigPath() const;
    };
}