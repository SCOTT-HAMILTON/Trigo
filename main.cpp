#include <QApplication>
#include <QTranslator>
#include <MainWindow.h>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);



    QTranslator translator;
    translator.load(QString(QApplication::applicationDirPath()+"/Trigo_")+locale);

    app.installTranslator(&translator);

    MainWindow window;
    window.show();

    return app.exec();
}
