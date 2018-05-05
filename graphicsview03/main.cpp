#include <QtWidgets>

int main(int argc,char* argv[ ])

{

    QApplication app(argc,argv);

    QGraphicsScene scene;

    scene.addText("Hello, world!");

    scene.setForegroundBrush(QColor(255, 255, 255, 100));
    scene.setBackgroundBrush(QPixmap("/Users/a710/GitHub/Learn_QT/graphicsview03/logo.png"));

    QGraphicsView view(&scene);

    view.show();

    return app.exec();

}
