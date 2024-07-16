


// テクスチャデータをアップロードする関数の定義
void UploadTextureData(ID3D12Resource* texture, const DirectX::ScratchImage& mipImages)
{
    // Meta情報を取得
    const DirectX::TexMetadata& metadata = mipImages.GetMetadata();
    // 全MipMapについて
    for (size_t mipLevel = 0; mipLevel < metadata.mipLevels; ++mipLevel)
    {
        // MipMapLevelを指定して各Imageを取得
        const DirectX::Image* img = mipImages.GetImage(mipLevel, 0, 0);
        // Textureに転送
        HRESULT hr = texture->WriteToSubresource(
            UINT(mipLevel),
            nullptr,
            img->pixels, // 元データアドレス
            UINT(img->rowPitch), // 1ラインサイズ
            UINT(img->slicePitch) // 1枚サイズ
        );
        assert(SUCCEEDED(hr));
    }
}