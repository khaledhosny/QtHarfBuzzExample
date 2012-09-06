#include <QtGui>

class  myWindow:public QWidget
{
public:
    myWindow():
    QWidget(){};
    ~myWindow(){};

    void paintEvent(QPaintEvent*) {
        QPainter painter(this);

        QString fileName = "amiri-regular.ttf";
        QRawFont rawFont = QRawFont(fileName, 50);

        QGlyphRun glyphRun = QGlyphRun();

        QVector<quint32> glyphIndexes(10);
        QVector<QPointF> glyphPositions(10);

        glyphIndexes[0] = 1;
        glyphPositions[0] = QPointF(0.0, 0.0);

        glyphRun.setRawFont(rawFont);
        glyphRun.setGlyphIndexes(glyphIndexes);
        glyphRun.setPositions(glyphPositions);
        glyphRun.setOverline(1);

        qDebug() << rawFont.familyName() << rawFont.ascent() << rawFont.descent();

        painter.drawGlyphRun(QPointF(10.0, 100.0), glyphRun);
    };
};


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    myWindow window;
    window.resize(400, 200);

    window.show();
    return app.exec();
}
