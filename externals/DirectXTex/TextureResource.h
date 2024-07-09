#pragma once
#pragma once

#include <d3d12.h>
#include <DirectXTex.h>

// テクスチャリソースを作成する関数の宣言
ID3D12Resource* CreateTextureResource(ID3D12Device* device, const DirectX::TexMetadata& metadata);
