#include <iostream>
using namespace std;

class Queues {
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_array[max];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert () {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //cek antrian penuh ga
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n" << endl;
            return;
        }

        //cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            //jika rear yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove () {
        //cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "\nQueue underflow\n" << endl;
            return;
        }

        cout << "\nThe elemen deleted from the queue is: " << queue_array[FRONT] << "\n";
        //jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            //jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display () {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        //cek apakah antrian kosong
        if (FRONT_position == -1)
        {
            cout << "\nQueue is empty\n" << endl;
            return;
        }

        cout << "\nElements in the queue are...\n";

        //jika FRONT <= REAR, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            //jika FRONT <= REAR, iterasi dari FRONT hingga akhir array, lalu dari awal array hingga REAR
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }