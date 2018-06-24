
project(juwenalia)

set(HEDEAR_FILES Plecak.h Prowiant.h Student.h WypelnijPlecak.h PosortujProdukty.h)
set(SOURCE_FILES Plecak.cpp Prowiant.cpp Student.cpp WypelnijPlecak.cpp PosortujProdukty.cpp)

add_library(libjuwenalia STATIC ${SOURCE_FILES})
target_include_directories(libjuwenalia PUBLIC .)

add_executable(juwenalia ${SOURCE_FILES} main.cpp)

target_link_libraries(juwenalia libjuwenalia)

