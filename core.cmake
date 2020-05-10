# // ------------------------------------------------------------------------------
#
# bt_Engine.Core
#
# // ------------------------------------------------------------------------------

# =================================================================================
# HEADERS
# =================================================================================

set ( BT_CORE_HEADERS
	# METRICS
	"core/utils/metrics/ILog.hxx"
	"core/utils/metrics/Log.hpp"
	"core/utils/metrics/BaseLog.hpp"
	# ASYNC
	"core/utils/async/IMutex.hxx"
	"core/utils/async/ILock.hxx"
	"core/utils/async/Mutex.hpp"
	"core/utils/async/BaseLock.hpp"
	# CONTAINERS
	"core/utils/containers/AsyncVector.hpp"
	"core/utils/containers/AsyncMap.hpp"
	"core/utils/containers/IMapIterator.hxx"
	"core/utils/containers/AsyncQueue.hpp"
	# TEXT
	"core/utils/text/IString.hxx"
	"core/utils/text/String.hpp"
	# GRAPHICS
	"core/graphics/IGraphics.hxx"
	"core/graphics/BaseGraphics.hpp"
	# RENDER
	# LOGIC
	# AUDIO
	# ENGINE
	"core/engine/IEngine.hxx"
	"core/engine/Engine.hpp"
	# CORE
	"core/bt.hpp" )

set ( BT_HEADERS ${BT_HEADERS} ${BT_CORE_HEADERS} )
set ( BT_PUBLIC_HEADERS ${BT_PUBLIC_HEADERS} ${BT_CORE_HEADERS} )

# =================================================================================
# SOURCES
# =================================================================================

set ( BT_CORE_SOURCES
	# METRICS
	"core/utils/metrics/Log.cpp"
	"core/utils/metrics/BaseLog.cpp"
	# ASYNC
	"core/utils/async/Mutex.cpp"
	"core/utils/async/BaseLock.cpp"
	# CONTAINERS
	# TEXT
	"core/utils/text/String.cpp"
	# GRAPHICS
	"core/graphics/BaseGraphics.cpp"
	# RENDER
	# LOGIC
	# AUDIO
	# ENGINE
	"core/engine/Engine.cpp"
	# CORE
	"core/bt.cpp" )

set ( BT_SOURCES ${BT_SOURCES} ${BT_CORE_SOURCES} )

# =================================================================================
# EXPORT
# =================================================================================

if ( DEFINED BT_HEADERS_EXPORT )
	set ( BT_HEADERS_EXPORT ${BT_HEADERS_EXPORT} ${BT_CORE_HEADERS} )
	set ( BT_SOURCES_EXPORT ${BT_SOURCES_EXPORT} ${BT_CORE_SOURCES} )
endif ( DEFINED BT_HEADERS_EXPORT )