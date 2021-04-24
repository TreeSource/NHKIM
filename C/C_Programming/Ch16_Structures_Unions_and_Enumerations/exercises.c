#include <stdio.h>
#include <stdbool.h>

enum shape_type {RECTANGLE, CIRCLE};
typedef enum day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday} Day;
typedef enum {empty, pawn, knight, bishop, rook, queen, king} Piece;
typedef enum {black, white} Color;

typedef struct 
{
    Piece p;
    Color c;
} Square;

Square board[8][8] = {{empty, black}};

struct pinball_machine
{
    char name[40];
    int year, player;
    enum {EM, SS} type;
};


typedef struct complex
    {
        double real, imaginary;
    } Complex;

struct date
{
    int month, day, year;
};
struct time
{
    int hours, minutes, seconds;
};
struct fraction
{
    int numerator, denominator;
};
struct color
{
    int red, green, blue;
};
struct point
{
    int x, y;
};
struct rectangle
{
    struct point upper_left, lower_right;
};
struct shape
{
    int shape_kind;
    struct point center;
    union 
    {
        struct 
        {
            int height, width;
        } rectangle;
        struct
        {
            int radius;
        } circle;
    } u;     
};


struct complex make_complex(double real, double imaginary);
struct complex add_complex(struct complex c1, struct complex c2);
Complex make_Complex(double real, double imaginary);
Complex add_Complex(Complex c1, Complex c2);

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

struct time split_time(long total_seconds);

int gcd(int i, int j);
struct fraction reduce(struct fraction f);
struct fraction add_fraction(struct fraction f1, struct fraction f2);
struct fraction subtract_fraction(struct fraction f1, struct fraction f2);
struct fraction multiply_fraction(struct fraction f1, struct fraction f2);
struct fraction divide_fraction(struct fraction f1, struct fraction f2);

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color c1, struct color c2);
struct color brighter(struct color c);
struct color darker(struct color c);

int area(struct rectangle r);
struct point center(struct rectangle r);
struct rectangle move(struct rectangle r, int x, int y);
bool is_in(struct rectangle r, struct point p);

int area_shape(struct shape s);
struct shape move_shape(struct shape s, int x, int y);
struct shape scale(struct shape s, double c);

int main (void)
{
    struct date d1, d2;
    d1.year = 2000;
    d1.month = 3;
    d1.day = 1;
    d2.year = 1999;
    d2.month = 3;
    d2.day = 1;
    printf("%d\n%d\n", day_of_year(d1), day_of_year(d2));
    printf("%d\n", compare_dates(d1, d2));

    struct time t;
    t = split_time(1000000);
    printf("%d:%d:%d\n", t.hours, t.minutes, t.seconds);

    struct fraction f = {618, 9};
    printf("%d/%d => ", f.numerator, f.denominator);
    f = reduce(f);
    printf("%d/%d\n", f.numerator, f.denominator);
    
    const struct color magenta = {.blue = 255, .red = 255};
    printf("%d,%d,%d\n", magenta.red, magenta.green, magenta.blue);

    struct shape
    {
        int shape_kind;
        struct point center;
        union 
        {
            struct 
            {
                int height, width;
            } rectangle;
            struct
            {
                int radius;
            } circle;
        } u;     
    };
    
    enum {NORTH, SOUTH, EAST, WEST} direction; int x, y;
    switch (direction)
    {
    case NORTH: y--; break;
    case SOUTH: y++; break;
    case EAST: x++; break;
    case WEST: x--; break;
    
    default:
        break;
    }
    enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
    int piece_value[] = {200, 9, 5, 3, 3, 1};
    int piece_value2[] =
    {
        [KING] = 200,
        [QUEEN] = 9,
        [ROOK] = 5,
        [KNIGHT] = 3,
        [BISHOP] = 3,
        [PAWN] = 1
    };

    return 0;
}

struct complex make_complex(double real, double imaginary)
{
    struct complex c = {real, imaginary};
    return c;
}

struct complex add_complex(struct complex c1, struct complex c2)
{
    c1.imaginary += c2.imaginary;
    c1.real += c2.real;
    return c1;
}


Complex make_Complex(double real, double imaginary)
{
    Complex c = {real, imaginary};
    return c;
}
Complex add_Complex(Complex c1, Complex c2)
{
    c1.real += c2.real;
    c1.imaginary += c2.imaginary;
    return c1;
}
int day_of_year(struct date d)
{
    int rtn = 0;
    for (int i = 1; i < d.month; ++i)
    {
        if (i == 2) 
        {
            if (d.year % 4 == 0) rtn += 29;
            else rtn += 28;
            continue;
            }
        else if (i < 8) 
        {
            if ((i % 2) == 1) rtn += 31;
            else rtn += 30;
        }
        else
        {
            if ((i % 2) == 1) rtn += 30;
            else rtn += 31;
        }
    }
    rtn += d.day;
    return rtn;
}
int compare_dates(struct date d1, struct date d2)
{
    if (d1.year != d2.year) return d1.year < d2.year ? -1 : 1;
    else if (d1.month != d2.month) return d1.month < d2.month ? -1 : 1;
    else if (d1.day != d2.day) return d1.day < d2.day ? -1: 1;
    else return 0;
}
struct time split_time(long total_seconds)
{
    struct time t;
    t.seconds = total_seconds % 60;
    t.minutes = (total_seconds / 60) % 60;
    t.hours = (total_seconds / 3600) % 24;
    return t;
}

int gcd(int i, int j)
{
    i = (i > 0) ? i : i * (-1);
    j = (j > 0) ? j : j * (-1);
    while (i != j)
    {
        if (i > j) i -= j;
        else j -= i;
    }
    return i;
}

struct fraction reduce(struct fraction f)
{
    int fgcd;
    fgcd = gcd(f.numerator, f.denominator);
    f.numerator /= fgcd; f.denominator /= fgcd;
    return f;
}
struct fraction add_fraction(struct fraction f1, struct fraction f2)
{
    f1.denominator *= f2.denominator;
    f1.numerator = f1.numerator * f2.denominator + f2.numerator * f1.numerator;
    return reduce(f1);
}
struct fraction subtract_fraction(struct fraction f1, struct fraction f2)
{
    f1.denominator *= f2.denominator;
    f1.numerator = f1.numerator * f2.denominator - f2.numerator * f1.numerator;
    return reduce(f1);
}
struct fraction multiply_fraction(struct fraction f1, struct fraction f2)
{
    f1.denominator *= f2.denominator;
    f1.numerator *= f2.numerator;
    return reduce(f1);
}
struct fraction divide_fraction(struct fraction f1, struct fraction f2)
{
    f1.denominator *= f2.numerator;
    f1.numerator *- f2.denominator;
    return reduce(f1);
}

struct color make_color(int red, int green, int blue)
{
    struct color c = {.red = red, .green = green, .blue = blue};
    return c;
}
int getRed(struct color c)
{
    return c.red;
}
bool equal_color(struct color c1, struct color c2)
{
    return (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue) ? true : false;
}
struct color brighter(struct color c)
{
    if (c.red == 0 && c.green == 0 && c.blue == 0)
    {
        c.red = 3; c.green = 3; c.blue = 3;
        return c;
    }
    c.red /= 0.7;
    c.blue /= 0.7;
    c.green /= 0.7;
    if (c.red > 255) c.red = 255;
    else if (c.blue > 255) c.blue = 255;
    else if (c.green > 255) c.green = 255;
    return c;
}
struct color darker(struct color c)
{
    c.red *= 0.7;
    c.green *= 0.7;
    c.blue *= 0.7;
    return c;
}

int area(struct rectangle r)
{
    return (r.lower_right.x - r.upper_left.x) * (r.upper_left.y - r.lower_right.y);
}
struct point center(struct rectangle r)
{
    struct point p;
    p.x = (r.lower_right.x - r.upper_left.x) / 2 + r.upper_left.x;
    p.y = (r.upper_left.y - r.lower_right.y) / 2 + r.lower_right.y;
    return p;
}
struct rectangle move(struct rectangle r, int x, int y)
{
    r.lower_right.x += x;
    r.upper_left.x += x;
    r.lower_right.y += y;
    r.upper_left.y += y;
    return r;
}
bool is_in(struct rectangle r, struct point p)
{
    return (p.x < r.lower_right.x && p.x > r.upper_left.x && p.y > r.lower_right.y && p.y < r.upper_left.y) ? true : false;
}

int area_shape(struct shape s)
{
    if (s.shape_kind == RECTANGLE) return s.u.rectangle.width * s.u.rectangle.height;
    else return s.u.circle.radius * s.u.circle.radius * 3.14;
}
struct shape move_shape(struct shape s, int x, int y)
{
    s.center.x += x;
    s.center.y += y;
    return s;
}
struct shape scale(struct shape s, double c)
{
    if (s.shape_kind = RECTANGLE)
    {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    }
    else s.u.circle.radius *= c;
    return s;
}