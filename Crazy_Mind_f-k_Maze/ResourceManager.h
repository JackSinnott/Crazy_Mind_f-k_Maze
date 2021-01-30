#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <Thor/Resources.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <unordered_map>

class ResourceManager
{
private:
	static thor::ResourceHolder<sf::Font, std::string, thor::Resources::RefCounted> m_fontManager;
	static std::map<std::string, std::shared_ptr<sf::Font>> m_fonts;

	static thor::ResourceHolder<sf::Texture, std::string, thor::Resources::RefCounted> m_textureManager;
	static std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;

	static thor::ResourceHolder<sf::SoundBuffer, std::string, thor::Resources::RefCounted> m_soundBufferManager;
	static std::map<std::string, std::shared_ptr<sf::SoundBuffer>> m_soundBuffers;

	static std::map<std::string, std::shared_ptr<sf::Sprite>> m_sprites;
public:
	static void loadFont(std::string path, std::string name);
	static std::shared_ptr<sf::Font> getFont(std::string name);

	static void loadTexture(std::string path, std::string name);
	static std::shared_ptr<sf::Texture> getTexture(std::string name);

	static void setSprite(std::string name, std::shared_ptr<sf::Sprite> sprite);
	static std::shared_ptr<sf::Sprite> getSprite(std::string name);

	static void loadSound(std::string t_path, std::string name);
	static std::shared_ptr<sf::SoundBuffer> getSoundBuffer(std::string name);

	static void loadAllResources();
};
#endif