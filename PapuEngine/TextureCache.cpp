#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>
using namespace std;

TextureCache::TextureCache()
{
}

GLTexture TextureCache::getTexture(std::string texturePath) {
	cout << texturePath << endl;
	if (_textureMap.count(texturePath) == 0) {
		cout << "^first load" << endl;
		GLTexture texture = ImageLoader::loadPNG(texturePath);
		_textureMap[texturePath] = texture;
		return texture;
	}
	return _textureMap[texturePath];
}


TextureCache::~TextureCache()
{
}
