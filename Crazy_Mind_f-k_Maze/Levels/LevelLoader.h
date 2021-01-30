#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "yaml-cpp\yaml.h"

/// <summary>
/// @brief A struct to store Background texture information.
/// 
/// </summary>
struct BackgroundData
{
	std::string m_fileName;
};

/// <summary>
/// @brief A struct to store Player texture information.
/// 
/// </summary>
struct PlayerData
{
	std::string m_fileName;
};

/// <summary>
/// @brief A struct representing all the Level Data.
/// 
/// Obstacles may be repeated and are therefore stored in a container.
/// </summary>
struct LevelData
{
	BackgroundData m_background;
	PlayerData m_player;
};

/// <summary>
/// @brief A class to manage level loading.
/// 
/// This class will manage level loading using YAML.
/// </summary>
class LevelLoader
{
public:

	/// <summary>
	/// @brief No-op default constructor.
	/// 
	/// </summary>
	LevelLoader() = default;

	/// <summary>
	/// @brief Loads and parses the yaml level file.
	/// The level file is identified by a number and is assumed to have
	/// the following format: "level" followed by number followed by .yaml extension
	/// E.g. "level1.yaml"
	/// The level information is stored in the specified LevelData object.
	/// If the filename is not found or the file data is invalid, an exception
	/// is thrown.
	/// </summary>
	/// <param name="t_levelNr">The level number</param>
	/// <param name="t_level">A reference to the LevelData object</param>
	static void load(int t_levelNr, LevelData& t_level);
};