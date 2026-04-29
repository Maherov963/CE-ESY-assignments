#include <stdio.h>
#include <string.h>

#define CAPACITY 10

typedef struct {
    char buffer[CAPACITY];
    int head;
    int tail;
} CircularBuffer;

// تهيئة
void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
}

// هل فارغ؟
int isEmpty(CircularBuffer *cb) {
    return cb->head == cb->tail;
}

// هل ممتلئ؟
int isFull(CircularBuffer *cb) {
    return ((cb->tail + 1) % CAPACITY) == cb->head;
}

// إضافة عنصر
int enqueue(CircularBuffer *cb, char value) {
    if (isFull(cb)) return -1;

    cb->buffer[cb->tail] = value;
    cb->tail = (cb->tail + 1) % CAPACITY;
    return 0;
}

// قراءة عنصر
int dequeue(CircularBuffer *cb, char *value) {
    if (isEmpty(cb)) return -1;

    *value = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % CAPACITY;
    return 0;
}

int main() {
    CircularBuffer cb;
    initBuffer(&cb);

    char name[100];

    printf("ادخل اسمك: ");
    fgets(name, sizeof(name), stdin);

    // حذف newline
    name[strcspn(name, "\n")] = '\0';

    printf("اهلا %s\n", name);

    // إدخال الأحرف
    for (int i = 0; name[i] != '\0'; i++) {
        if (enqueue(&cb, name[i]) == -1) {
            printf("المخزن ممتلئ (Overflow)\n");
            break;
        }
    }

    // إخراج الأحرف
    char ch;
    while (dequeue(&cb, &ch) != -1) {
        printf("قراءة: %c\n", ch);
    }

    return 0;
}