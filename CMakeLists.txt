add_library(OneWireLib INTERFACE)

target_sources(OneWireLib INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/OneWire.cpp
    ${CMAKE_CURRENT_LIST_DIR}/HAL.cpp
    )

target_include_directories(OneWireLib INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/util/
    ${CMAKE_CURRENT_LIST_DIR}/
    )
target_link_libraries(OneWireLib INTERFACE pico_stdlib hardware_gpio hardware_sync)