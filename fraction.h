#ifndef FRACTION_H
#define FRACTION_H
#pragma once
#include<stdio.h>
#include "fraction.h"

struct fraction {
    int nume;
    int denom;
};

typedef struct fraction frac;

int gcd(int a, int b);
void rearfrac(frac* x);
frac getfrac();
void putfrac(frac x);
void frac_op(frac a, frac b, frac* c, char op);
short int frac_cmp(frac a, frac b);

int gcd(int a, int b) {
    if (a < 0)a = -a;
    if (b < 0)b = -b;
    return b > 0 ? gcd(b, a % b) : a;
}

void rearfrac(frac* x) {
    if (x->denom < 0 && x->nume < 0 || x->nume > 0 && x->denom < 0) {
        x->denom = -(x->denom);
        x->nume = -(x->nume);
    }
    int gcd_nd = gcd(x->denom, x->nume);
    if (gcd_nd == 0)gcd_nd = 1;
    if (gcd_nd <= ((x->nume) > 0 ? (x->nume) : -(x->nume))) {
        x->denom /= gcd_nd;
        x->nume /= gcd_nd;
    }
}

frac getfrac() {
    frac op;
    scanf("%d/%d", &op.nume, &op.denom);
    return op;
}

void putfrac(frac x) {
    if (x.denom == 0) {
        printf("inf");
        return;
    }
    else if (x.denom == 1) {
        printf("%d", x.nume);
        return;
    }
    printf("%d/%d", x.nume, x.denom);
}

void frac_op(frac a, frac b, frac* c, char op) {
    rearfrac(&a);
    rearfrac(&b);
    int plus = 0;
    int gcd_nn = gcd(a.denom, b.denom);
    if (gcd_nn == 0)gcd_nn = 1;
    int lcmnn = ((a.denom * b.denom) > 0 ? (a.denom * b.denom) : -(a.denom * b.denom)) / gcd_nn;
    if (op == '+') {
        if (a.denom != 0) { plus = lcmnn / a.denom; }
        else plus = 1;
        a.denom *= plus;
        a.nume *= plus;
        if (b.denom != 0) { plus = lcmnn / b.denom; }
        else plus = 1;
        b.denom *= plus;
        b.nume *= plus;
        c->denom = a.denom;
        c->nume = a.nume + b.nume;
    }
    else if (op == '-') {
        if (a.denom != 0) { plus = lcmnn / a.denom; }
        else plus = 1;
        a.denom *= plus;
        a.nume *= plus;
        if (b.denom != 0) { plus = lcmnn / b.denom; }
        else plus = 1;
        b.denom *= plus;
        b.nume *= plus;
        c->denom = a.denom;
        c->nume = a.nume - b.nume;
    }
    else if (op == '*') {
        c->denom = a.denom * b.denom;
        c->nume = a.nume * b.nume;
    }
    else if (op == '/') {
        c->denom = a.denom * b.nume;
        c->nume = a.nume * b.denom;
    }
    else if (op == '%') {
        if (a.denom != 0) { plus = lcmnn / a.denom; }
        else plus = 1;
        a.denom *= plus;
        a.nume *= plus;
        if (b.denom != 0) { plus = lcmnn / b.denom; }
        else plus = 1;
        b.denom *= plus;
        b.nume *= plus;
        if (a.nume < b.nume) {
            c->denom = a.denom;
            c->nume = a.nume;
        }
        else {
            c->denom = b.nume;
            c->nume = a.nume;
            int n = c->nume / c->denom;
            c->nume = a.nume - b.nume * n;
            c->denom = a.denom;
        }
    }
    rearfrac(c);
}

short int frac_cmp(frac a, frac b) {
    rearfrac(&a);
    rearfrac(&b);
    int gcd_nn = gcd(a.denom, b.denom);
    if (gcd_nn == 0)gcd_nn = 1;
    int lcmnn = ((a.denom * b.denom) > 0 ? (a.denom * b.denom) : -(a.denom * b.denom)) / gcd_nn;
    int plus = 1;
    if (a.denom != 0) { plus = lcmnn / a.denom; }
    else plus = 1;
    a.denom *= plus;
    a.nume *= plus;
    if (b.denom != 0) { plus = lcmnn / b.denom; }
    else plus = 1;
    b.denom *= plus;
    b.nume *= plus;
    if (a.denom == b.denom && a.nume == b.nume || a.denom == 0 && b.denom == 0 && (a.nume > 0 && b.nume > 0 || a.nume < 0 && b.nume < 0))return 1;
    else if (a.nume > b.nume || a.nume > 0 && a.denom == 0)return 2;
    else if (a.nume < b.nume || b.nume>0 && b.denom == 0)return 0;
}

#endif

