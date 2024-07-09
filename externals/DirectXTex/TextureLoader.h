#pragma once
#pragma once

#include <string>
#include <DirectXTex.h>

// テクスチャを読み込む関数の宣言
DirectX::ScratchImage LoadTexture(const std::string& filePath);

// 文字列変換関数の宣言
std::wstring ConvertString(const std::string& str);
