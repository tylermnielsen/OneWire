add_library(OneWire INTERFACE)


target_sources(OneWire INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/OneWire.cpp
    ${CMAKE_CURRENT_LIST_DIR}/HAL.cpp
)

target_include_directories(OneWire INTERFACE ${CMAKE_CURRENT_LIST_DIR}/util)
target_link_libraries(OneWire INTERFACE pico_stdlib hardware_gpio hardware_sync)