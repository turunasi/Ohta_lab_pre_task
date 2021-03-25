float newtonInterpolation(int N, float x[], float fx[], float xs) {
    float h = x[1] - x[0];
    float s = (xs - x[0]) / h;
    float deltas_x[N-1];
    float deltas[N];
    for (int i=0; i <= N; i++) {
        deltas[i] = fx[i];
    }
    float new_deltas[N-1];
    for (int i=N; i == 1; i--) {
        for (int j = 0; j < i; j++) {
            new_deltas[j] = deltas[j+1] - deltas[j];
        }
        deltas_x[N-i] = new_deltas[0]; 
        float deltas[i];
        for (int j = 0; j < i; j++) {
            deltas[j] = new_deltas[j];
        }
        float new_deltas[i-1];
    }
    float ans = x[0];
    float coeff = s;
    for (int i=0; i < N; i++) {
        ans += coeff * deltas_x[i];
        coeff *= (s-i-1)/(i+1);
    }
    return ans;
}