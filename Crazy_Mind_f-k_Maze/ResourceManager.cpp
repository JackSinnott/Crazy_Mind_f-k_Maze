#include "ResourceManager.h"

thor::ResourceHolder<sf::Font, std::string, thor::Resources::RefCounted> ResourceManager::m_fontManager;
std::map<std::string, std::shared_ptr<sf::Font>> ResourceManager::m_fonts;

thor::ResourceHolder<sf::Texture, std::string, thor::Resources::RefCounted> ResourceManager::m_textureManager;
std::map<std::string, std::shared_ptr<sf::Texture>> ResourceManager::m_textures;

std::map<std::string, std::shared_ptr<sf::Sprite>> ResourceManager::m_sprites;

thor::ResourceHolder<sf::SoundBuffer, std::string, thor::Resources::RefCounted> ResourceManager::m_soundBufferManager;
std::map<std::string, std::shared_ptr<sf::SoundBuffer>> ResourceManager::m_soundBuffers;

/// <summary>
/// gets the font manager to load the font and then assign it to the map so we can get it later
/// need to save it to a new map as it seems that we get an exception if we try to load directly from the resource manager
/// a second time 
/// </summary>
/// <param name="path">path to the font</param>
/// <param name="name">name to be assigned to the key of the map</param>
void ResourceManager::loadFont(std::string path, std::string name)
{
	std::shared_ptr<sf::Font> font = m_fontManager.acquire(name, thor::Resources::fromFile<sf::Font>(path));
	if (m_fonts.find(name) == m_fonts.end())
	{
		m_fonts[name] = font;
	}
}

/// <summary>
/// tries to get the font if it is in the map and already loaded
/// otherwise it will throw a not found exception
/// </summary>
/// <param name="name">name of the font to be loaded</param>
/// <returns>returns the font if it is in the map, otherwise throws an exception</returns>
std::shared_ptr<sf::Font> ResourceManager::getFont(std::string name)
{
	if (m_fonts.find(name) != m_fonts.end())
	{
		return m_fonts[name];
	}
	else
	{
		throw std::exception("Not found");
	}
}

void ResourceManager::loadTexture(std::string path, std::string name)
{
	std::shared_ptr<sf::Texture> texture = m_textureManager.acquire(name, thor::Resources::fromFile<sf::Texture>(path));
	if (m_textures.find(name) == m_textures.end())
	{
		m_textures[name] = texture;
	}
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(std::string name)
{
	if (m_textures.find(name) != m_textures.end())
	{
		return m_textures[name];
	}
	else
	{
		throw std::exception("Not found");
	}
}

void ResourceManager::setSprite(std::string name, std::shared_ptr<sf::Sprite> sprite)
{
	if (m_sprites.find(name) == m_sprites.end())
	{
		m_sprites[name] = sprite;
	}
}

std::shared_ptr<sf::Sprite> ResourceManager::getSprite(std::string name)
{
	if (m_sprites.find(name) != m_sprites.end())
	{
		return m_sprites[name];
	}
	else
	{
		throw std::exception("Not found");
	}
}

void ResourceManager::loadSound(std::string t_path, std::string name)
{
	std::shared_ptr<sf::SoundBuffer> soundBuffer = m_soundBufferManager.acquire(name, thor::Resources::fromFile<sf::SoundBuffer>(t_path));
	if (m_soundBuffers.find(name) == m_soundBuffers.end())
	{
		m_soundBuffers[name] = soundBuffer;
	}
}

std::shared_ptr<sf::SoundBuffer> ResourceManager::getSoundBuffer(std::string name)
{
	if (m_soundBuffers.find(name) != m_soundBuffers.end())
	{
		return m_soundBuffers[name];
	}
	else
	{
		throw std::exception("Not found");
	}
}

void ResourceManager::loadAllResources()
{
	
}
