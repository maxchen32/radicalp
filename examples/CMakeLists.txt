# 遍历 examples 目录下的所有源文件
file(GLOB EXAMPLE_SOURCES *.cpp)

# 遍历每个源文件，生成对应的可执行文件
foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    # 获取每个示例的文件名，用作可执行文件名
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} ${PROJECT_NAME})
endforeach()
