HEADERS += \
  colors.h \
  basic_object3d.h \
  cube.h \
  object3d.h \
  axis.h \
  plyobj.h \
  revobj.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  file_ply_stl.h \
  rueda.h \
  cilindro.h \
  esfera.h \
  eje.h \
  rueda_eje.h \
  materials.h \
  function.h \
  chess_board.h \
  Abase.h \ 
  Aarm.h \
  Atip.h \
  Aend.h \
  Acompass.h \
  Phone.h

SOURCES += \
  basic_object3d.cc \
  cube.cpp \
  object3d.cc \
  axis.cc \
  plyobj.cpp \
  revobj.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
  file_ply_stl.cc \
  rueda.cc \
  cilindro.cc \
  esfera.cc \
  eje.cc \
  rueda_eje.cc \
  chess_board.cc \
  Abase.cc \ 
  Aarm.cc \
  Atip.cc  \
  Aend.cc \
  Acompass.cc \
  Phone.cc

LIBS += -L/usr/X11R6/lib64 -lGL -lpng -L/usr/local/lib -lfreetype
INCLUDEPATH += "/usr/include/freetype2"
CONFIG += c++11
QT += widgets
