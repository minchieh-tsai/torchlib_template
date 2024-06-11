project(lib1)

add_library(${PROJECT_NAME} SHARED
	lib1-pub-impl.cpp
)

add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(${PROJECT_NAME}
PUBLIC
	cxx_std_17
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
    ${TORCH_LIBRARIES}
    ${OpenCV_LIBS}
)

if(BUILD_TESTING)
	add_subdirectory(tests)
endif()

# install target
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)