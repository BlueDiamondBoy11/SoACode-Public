///
/// VoxelSpaceConversions.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 27 Jan 2015
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Converts between the different voxel coordinate spaces
///

#pragma once

#ifndef VoxelSpaceConversions_h__
#define VoxelSpaceConversions_h__

#include "Constants.h"
#include "VoxelCoordinateSpaces.h"
#include <Vorb/utils.h>

/// Namespace for converting between the different voxel and chunk coordinate spaces
namespace VoxelSpaceConversions {

#define W_X 0
#define W_Y 1
#define W_Z 2
    /// Maps face-space coordinate axis to world-space coordinates.
    /// [face]
    const i32v3 GRID_TO_WORLD[6] = {
        i32v3(W_X, W_Y, W_Z), // TOP
        i32v3(W_Z, W_X, W_Y), // LEFT
        i32v3(W_Z, W_X, W_Y), // RIGHT
        i32v3(W_X, W_Z, W_Y), // FRONT
        i32v3(W_X, W_Z, W_Y), // BACK
        i32v3(W_X, W_Y, W_Z) }; // BOTTOM
#undef W_X
#undef W_Y
#undef W_Z

    /// Multiply by the face-space Y axis in order to get the correct direction
    /// for its corresponding world space axis
    /// [face]
    const int FACE_Y_MULTS[6] = { 1, -1, 1, 1, -1, -1 };
    /// Multiply by the grid-space X,Z axis in order to get the correct direction
    /// for its corresponding world-space axis
    /// [face][rotation]
    const i32v2 FACE_TO_WORLD_MULTS[6][4] = {
        { i32v2(1, 1), i32v2(1, -1), i32v2(-1, -1), i32v2(-1, 1) }, // TOP
        { i32v2(1, -1), i32v2(-1, -1), i32v2(-1, 1), i32v2(1, 1) }, // LEFT
        { i32v2(-1, -1), i32v2(-1, 1), i32v2(1, 1), i32v2(1, -1) }, // RIGHT
        { i32v2(1, -1), i32v2(-1, -1), i32v2(-1, 1), i32v2(1, 1) }, // FRONT
        { i32v2(-1, -1), i32v2(-1, 1), i32v2(1, 1), i32v2(1, -1) }, // BACK
        { i32v2(1, -1), i32v2(-1, -1), i32v2(-1, 1), i32v2(1, 1) } }; // BOTTOM

    /// Multiply by the grid-space X,Z axis in order to get the correct position
    /// for its corresponding unrotated face-space position
    /// [rotation]
    const i32v2 GRID_TO_FACE_MULTS[4] = {
        i32v2(1, 1), i32v2(1, -1), i32v2(-1, -1), i32v2(-1, 1)
    };

    /// Gets multipliers for converting face direction to world direction
    extern f32v3 getCoordinateMults(const ChunkFacePosition2D& facePosition);
    extern f32v3 getCoordinateMults(const ChunkFacePosition3D& facePosition);
    /// Gets coordinate mappings for converting face position to world position
    extern i32v3 getCoordinateMapping(const ChunkFacePosition2D& facePosition);
    extern i32v3 getCoordinateMapping(const ChunkFacePosition3D& facePosition);

    /// Converts from voxel grid-space to chunk grid-space
    /// Does not affect rotation or face
    /// @param voxelPosition: The voxel grid position
    /// @return the chunk grid position
    extern ChunkGridPosition2D voxelGridToChunkGrid(const VoxelGridPosition2D& voxelPosition);
    extern ChunkGridPosition3D voxelGridToChunkGrid(const VoxelGridPosition3D& voxelPosition);
    /// Converts from chunk grid-space to voxel grid-space
    /// Does not affect rotation or face
    /// @param gridPosition: The chunk grid position
    /// @return the voxel position
    extern VoxelGridPosition2D chunkGridToVoxelGrid(const ChunkGridPosition2D& gridPosition);
    extern VoxelGridPosition3D chunkGridToVoxelGrid(const ChunkGridPosition3D& gridPosition);
    /// Converts from voxel grid-space to chunk grid-space
    /// Does not affect rotation or face
    /// @param voxelPosition: The voxel grid position
    /// @return the chunk grid position
    extern ChunkFacePosition2D voxelFaceToChunkFace(const VoxelFacePosition2D& voxelPosition);
    extern ChunkFacePosition3D voxelFaceToChunkFace(const VoxelFacePosition3D& voxelPosition);
    /// Converts from chunk face-space to voxel face-space
    /// Does not affect rotation or face
    /// @param gridPosition: The voxel face position
    /// @return the voxel position
    extern VoxelFacePosition2D chunkFaceToVoxelFace(const ChunkFacePosition2D& gridPosition);
    extern VoxelFacePosition3D chunkFaceToVoxelFace(const ChunkFacePosition3D& gridPosition);
    /// Converts from grid-space to face-space
    /// @param gridPosition: The voxel face position
    /// @return the face position
    extern VoxelFacePosition2D voxelGridToFace(const VoxelGridPosition2D& gridPosition);
    extern VoxelFacePosition3D voxelGridToFace(const VoxelGridPosition3D& gridPosition);
    /// Converts from grid-space to face-space
    /// @param gridPosition: The chunk face position
    /// @return the face position
    extern ChunkFacePosition2D chunkGridToFace(const ChunkGridPosition2D& gridPosition);
    extern ChunkFacePosition3D chunkGridToFace(const ChunkGridPosition3D& gridPosition);
    /// Converts from face-space to world-space
    /// @param facePosition: The face position
    /// @param voxelWorldRadius: Radius of the world in units of voxels
    /// @return the world position
    extern f64v3 voxelFaceToWorld(const VoxelFacePosition2D& facePosition, f64 voxelWorldRadius);
    extern f64v3 voxelFaceToWorld(const VoxelFacePosition3D& facePosition, f64 voxelWorldRadius);
    /// Converts from face-space to world-space
    /// @param facePosition: The face position
    /// @param voxelWorldRadius: Radius of the world in units of voxels
    /// @return the world position
    extern f64v3 chunkFaceToWorld(const ChunkFacePosition2D& facePosition, f64 voxelWorldRadius);
    extern f64v3 chunkFaceToWorld(const ChunkFacePosition3D& facePosition, f64 voxelWorldRadius);
    /// Converts from face-space to normalized world-space
    /// @param facePosition: The face position
    /// @param voxelWorldRadius: Radius of the world in units of voxels
    /// @return the normalized world position
    extern f64v3 voxelFaceToWorldNormalized(const VoxelFacePosition2D& facePosition, f64 voxelWorldRadius);
    extern f64v3 voxelFaceToWorldNormalized(const VoxelFacePosition3D& facePosition, f64 voxelWorldRadius);
    /// Converts from face-space to normalized world-space
    /// @param facePosition: The face position
    /// @param voxelWorldRadius: Radius of the world in units of voxels
    /// @return the normalized world position
    extern f64v3 chunkFaceToWorldNormalized(const ChunkFacePosition2D& facePosition, f64 voxelWorldRadius);
    extern f64v3 chunkFaceToWorldNormalized(const ChunkFacePosition3D& facePosition, f64 voxelWorldRadius);
    /// Converts from world-space to unrotated voxel-space
    /// @param worldSpace: World position in units of voxels. @pre should rotated so that the planet has
    ///   a relative orientation of 0
    /// @return the voxel position
    extern VoxelGridPosition3D worldToVoxelGrid(const f64v3& worldPosition, f64 voxelWorldRadius);
}

#endif // VoxelSpaceConversions_h__