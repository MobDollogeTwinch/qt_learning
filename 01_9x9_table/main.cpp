#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QString>
#include <QWidget>

class Label : public QLabel {
public:
  explicit Label(QWidget *parent = nullptr) : QLabel(parent) {
    setAlignment(Qt::AlignCenter);
    setStyleSheet(R"(
        QLabel {
            margin: 10px;
            font-size: 20px;
        }
    )");
  }
};

class MainWindow : public QMainWindow {
public:
  explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
    setWindowTitle("九九乘法表");
    QGridLayout *layout = new QGridLayout;
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);

    for (int i = 1; i <= 9; ++i) {
      for (int j = 1; j <= 9; ++j) {
        Label *label = new Label;
        label->setText(QString("%1 * %2 = %3").arg(i).arg(j).arg(i * j));
        layout->addWidget(label, i - 1, j - 1);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow _;
  _.show();
  return app.exec();
}