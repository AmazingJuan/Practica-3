TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Sources/Archivos.cpp \
    Sources/Codificacion.cpp \
    Sources/Decodificacion.cpp \
    Sources/Menus.cpp \
    Sources/Programas.cpp \
    Sources/Utilidades.cpp \
    Sources/Validacion.cpp \
    main.cpp

HEADERS += \
    Headers/Archivos.h \
    Headers/Codificacion.h \
    Headers/Decodificacion.h \
    Headers/Importaciones.h \
    Headers/Menus.h \
    Headers/Programas.h \
    Headers/Utilidades.h \
    Headers/Validacion.h
