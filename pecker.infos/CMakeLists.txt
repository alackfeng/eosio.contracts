add_contract(pecker.infos pecker.infos ${CMAKE_CURRENT_SOURCE_DIR}/src/pecker.infos.cpp)
target_include_directories(pecker.infos.wasm
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(pecker.infos.wasm
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
