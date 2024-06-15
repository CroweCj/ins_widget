cmake_minimum_required(VERSION 3.10)

project(INS_WIDGET_TEST)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)


#ui 
if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "aarch64")
    set(CMAKE_PREFIX_PATH "/opt/qt5.12.12_arm/")
    set(Qt5_DIR "/opt/qt5.12.12_arm/lib/cmake/Qt5")
    message("aarch64 cpu")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
    set(CMAKE_PREFIX_PATH "/opt/Qt-5.15.2/5.15.2/gcc_64")
    set(Qt5_DIR "/opt/Qt-5.15.2/5.15.2/gcc_64")
    message("x86_64 cpu")
endif() 

find_package(Qt5 COMPONENTS Widgets Gui Core Concurrent Charts Network REQUIRED)
message(${Qt5_VERSION})


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS "./")

file(GLOB UI_SRC_LIST "./*.cpp")
file(GLOB UI_HEADER_LIST "./*.h")
file(GLOB UI_RCC_FILES "./*.qrc")
qt5_wrap_ui(UI_FILES "./*.ui")

add_executable(${PROJECT_NAME} 
              ${UI_SRC_LIST} 
              ${UI_HEADER_LIST} 
              ${UI_FILES} 
              ${UI_RCC_FILES})

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    Qt5::Gui
    Qt5::Core
    Qt5::Concurrent
    Qt5::Charts
    pthread
    ${OpenCV_LIBS}    
)
