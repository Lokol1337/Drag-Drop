QT += widgets

HEADERS     = \
    botdesk.h \
    bots.h \
    game.h \
    gold.h \
    heroes.h \
    label.h \
    playerdesk.h \
    seconds.h
RESOURCES   = draggableicons.qrc \

SOURCES     = \
              botdesk.cpp \
              bots.cpp \
              game.cpp \
              gold.cpp \
              heroes.cpp \
              label.cpp \
              main.cpp \
              playerdesk.cpp \
              seconds.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/draganddrop/draggableicons
INSTALLS += target
