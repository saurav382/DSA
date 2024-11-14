
#include <stdio.h>
#include <ctype.h>  

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

int pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

int evaluatePostfix(char* postfix) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');  
        }
        else {
            int val1 = pop(&s);
            int val2 = pop(&s);

            switch (ch) {
                case '+':
                    push(&s, val2 + val1);
                    break;
                case '-':
                    push(&s, val2 - val1);
                    break;
                case '*':
                    push(&s, val2 * val1);
                    break;
                case '/':
                    push(&s, val2 / val1);
                    break;
            }
        }
    }

    return pop(&s);
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
