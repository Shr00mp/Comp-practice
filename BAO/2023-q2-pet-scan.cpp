#include <bits/stdc++.h>
using namespace std;
#include <cmath>

void part_a_i() {
    // Proof written on paper
}

double degree_to_radians(double angle) {
    return angle * M_PI / 180.0;
}

double radians_to_degree(double angle) {
    return angle * (180 / M_PI);
}

vector<double> polar_to_cartesian(double angle, double magnitude) {
    angle = 360 - angle + 90;
    angle = degree_to_radians(angle);
    double sin_val, cos_val;
    sin_val = sin(angle);
    cos_val = cos(angle);
    double x_coord, y_coord;
    x_coord = magnitude * cos_val;
    y_coord = magnitude * sin_val;
    return {x_coord, y_coord};
}

vector<double> cartesian_to_polar(double x, double y) {
    double angle = atan(y/x);
    angle = radians_to_degree(angle);
    if (x>=0 && y>=0) {
        angle = angle;
    } else if (x<=0 && y>=0) {
        angle = 180 + angle;
    } else if (x<=0 && y<=0) {
        angle = 180 + angle;
    } else if (x>=0 && y<=0) {
        angle = 360 + angle;
    }
    angle = 360 - angle + 90;
    double magnitude;
    magnitude = sqrt(pow(x, 2) + pow(y, 2));
    return {angle, magnitude};
}

double find_angle(int camera_num, char a_b_c) {
    // Each camera represents a full 11.25 degrees
    double angle = (camera_num-1)*11.25;
    if (a_b_c == 'A') {
        angle += 2.8125;
    } else if (a_b_c == 'B') {
        angle += (2*2.8125);
    } else if (a_b_c == 'C') {
        angle += (3*2.8125);
    }
    return angle;
}

void part_a_ii() {
    // Strategy is to write two functions, polar <-> cartesian - Done 
    // We can find the location of the two points using polar coordinates - Done
    // Then, convert to cartesian - Done
    // We know how far along the line the location of tracer is - Done
    // After getting cartesian coordinates of tracer, convert back to polar
    double time1, time2; 
    int camera1, camera2;
    char abc1, abc2;
    cin >> time1 >> time2;
    cin >> camera1 >> abc1;
    cin >> camera2 >> abc2;
    vector<double> photon1_polar(2); vector<double> photon2_polar(2);
    photon1_polar[0] = 45.0; photon2_polar[0] = 45.0;
    photon1_polar[1] = find_angle(camera1, abc1);
    photon2_polar[1] = find_angle(camera2, abc2);
    vector<double> photon1_cartesian = polar_to_cartesian(photon1_polar[1], photon1_polar[0]);
    vector<double> photon2_cartesian = polar_to_cartesian(photon2_polar[1], photon2_polar[0]);

    double x_diff = photon2_cartesian[0] - photon1_cartesian[0];
    double y_diff = photon2_cartesian[1] - photon1_cartesian[1];
    double way_along = time1/(time1 + time2);
    double tracer_x, tracer_y;
    tracer_x = photon1_cartesian[0] + (x_diff * way_along);
    tracer_y = photon1_cartesian[1] + (y_diff * way_along);
    vector<double> tracer_polar = cartesian_to_polar(tracer_x, tracer_y);
    double tracer_angle = round(100.0 * tracer_polar[0] + 1e-9) / 100.0;
    double tracer_magnitude = round(100.0 * tracer_polar[1] + 1e-9) / 100.0;
    if (tracer_angle >= 360) {
        cout << fixed << setprecision(2) << 0.00 << " " << tracer_magnitude;
    }
    else {
        cout << fixed << setprecision(2) << tracer_angle << " " << tracer_magnitude;
    }
}

void part_b() {
    // 1.10cm (3sf)
    // Between e.g. A and B on one camera
    // Use cosine rule to find length of AB, then divide by 2
}

int main() {
    part_a_ii();
}
