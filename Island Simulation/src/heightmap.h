#pragma once

#include "vertexBufferObject.h"
#include "shaders.h"
#include "common_header.h"

#include <FreeImage.h>

#define NUMTERRAINSHADERS 3

/****************************************************************************************

Class:		CMultiLayeredHeightmap

Purpose:	Wraps FreeType heightmap loading and rendering, also allowing
			to use multiple layers of textures with transitions between them.

****************************************************************************************/

class CMultiLayeredHeightmap
{
public:
	static bool LoadTerrainShaderProgram();
	static void ReleaseTerrainShaderProgram();

	bool LoadHeightMapFromImage(string sImagePath);
	void ReleaseHeightmap();

	void RenderHeightmap();

	void SetRenderSize(float fQuadSize, float fHeight);
	void SetRenderSize(float fRenderX, float fHeight, float fRenderZ);

	int GetNumHeightmapRows();
	int GetNumHeightmapCols();

	float HeightAt(const glm::vec3& position);

	static CShaderProgram* GetShaderProgram();

	CMultiLayeredHeightmap();

private:
	UINT uiVAO;

	bool bLoaded;
	bool bShaderProgramLoaded;
	int iRows;
	int iCols;

	glm::vec3 vRenderScale;

	CVertexBufferObject vboHeightmapData;
	CVertexBufferObject vboHeightmapIndices;

	static CShaderProgram spTerrain;
	static CShader shTerrainShaders[NUMTERRAINSHADERS];

	vector< vector< glm::vec3> > vVertexData;
};