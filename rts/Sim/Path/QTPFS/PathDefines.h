#ifndef QTPFS_DEFINES_HDR
#define QTPFS_DEFINES_HDR

#include <limits>

// #define QTPFS_NO_LOADSCREEN
#define QTPFS_SUPPORT_PARTIAL_SEARCHES
// #define QTPFS_TRACE_PATH_SEARCHES
#define QTPFS_SMOOTH_PATHS
// #define QTPFS_CONSERVATIVE_NODE_SPLITS
// #define QTPFS_DEBUG_NODE_HEAP
#define QTPFS_CORNER_CONNECTED_NODES
// #define QTPFS_SLOW_ACCURATE_TESSELATION
// #define QTPFS_ORTHOPROJECTED_EDGE_TRANSITIONS
#define QTPFS_ENABLE_MICRO_OPTIMIZATION_HACKS
// #define QTPFS_CONSERVATIVE_NEIGHBOR_CACHE_UPDATES

#define QTPFS_MAX_SMOOTHING_ITERATIONS 8

#define QTPFS_MAX_NETPOINTS_PER_NODE_EDGE 1
#define QTPFS_NETPOINT_EDGE_SPACING_SCALE (1.0f / (QTPFS_MAX_NETPOINTS_PER_NODE_EDGE + 1))

#define QTPFS_POSITIVE_INFINITY (std::numeric_limits<float>::infinity())
#define QTPFS_CLOSED_NODE_COST (1 << 24)

#define QTPFS_LAST_FRAME (std::numeric_limits<int>::max())

#define QTPFS_MAX_NODE_SIZE 256
#define QTPFS_BAD_ROOT_NODE_SIZE 64

#define QTPFS_SHARE_PATH_MIN_SIZE 2
#define QTPFS_SHARE_PATH_MAX_SIZE 16

namespace QTPFS {
    constexpr int SEARCH_DIRS = 2;
}

#endif

