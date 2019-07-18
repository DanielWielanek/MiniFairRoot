Set(INCLUDE_DIRECTORIES
${CMAKE_SOURCE_DIR}
${CMAKE_SOURCE_DIR}/base
${CMAKE_SOURCE_DIR}/tools
${CMAKE_SOURCE_DIR}/fairlogger
)


Set(SYSTEM_INCLUDE_DIRECTORIES
 ${ROOT_INCLUDE_DIR} 
)

Set(LINK_DIRECTORIES
  ${ROOT_LIBRARY_DIR}
)

Include_Directories(${INCLUDE_DIRECTORIES})
Include_Directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})
 
Link_Directories(${LINK_DIRECTORIES})

set(SRCS
FairRootManager.cxx
FairRun.cxx
FairRunAna.cxx
FairTask.cxx
FairField.cxx
FairMCEventHeader.cxx
FairSource.cxx
FairFileSource.cxx
FairEventHeader.cxx
)


Set(HEADERS )
Set(LINKDEF FairBaseLinkDef.h)
Set(LIBRARY_NAME Base)
Set(DEPENDENCIES Core Tree Geom)

GENERATE_LIBRARY()


