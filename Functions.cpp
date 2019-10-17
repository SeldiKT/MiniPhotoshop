void biner(int**  A, bool**  B, int T, int N, int M)
/* Membuat citra biner dari citra A berdasarkan nilai ambang
(threshold) T yang dispesifikasikan. Ukuran citra adalah N  M.
citra_biner adalah tipe data untuk citra biner).
*/
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			if (A[i][j] < T)
				B[i][j] = 0;
			else
				B[i][j] = 1;
		}
}void negatif(int** A, int** B, int N, int M)
/* Membuat citra negatif dari citra A. Hasilnya disimpan di
dalam citra B. Ukuran citra adalah N  M.
*/
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			B[i][j] = 255 - A[i][j];
		}
}void image_brightening(int** A, int b, int** B, int N, int M)
/* Pencerahan citra dengan menjumlahkan setiap pixel di dalam citra A dengan
sebuah skalar b. Hasil disimpan di dalam citra B. Citra berukuran N  M. */
{
	int i, j, temp;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			temp = A[i][j] + b;
			/* clipping */
			if (temp < 0)
				B[i][j] = 0;
			else
				if (temp > 255)
					B[i][j] = 255;
				else
					B[i][j] = temp;
		}
}void grayscale(int** R, int** G, int** B, int** Gray, int N, int M) {	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			Gray[i][j] = 0.299 * R[i][j] + 0.587 * G[i][j] + 0.144 * B[i][j];
		}}void addvalues(int** A, int** B, int** C, int N, int M) {
	int i, j, temp;	for (i = 0; i < N; i++) {		for (i = 0; i < M; i++) {			int temp = B[i][j] + A[i][j];			if (temp > 255) {				C[i][j] = 255;			}			else {				C[i][j] = temp;			}		}	}}void substractvalues(int** A, int** B, int** C, int N, int M) {
	int i, j, temp;	for (i = 0; i < N; i++) {		for (i = 0; i < M; i++) {			int temp = A[i][j] - B[i][j];			if (temp != 0) {				C[i][j] = 255;			}			else {				C[i][j] = temp;			}		}	}}void addvalues(int** A, int B, int** C, int N, int M) {
	int i, j, temp;	for (i = 0; i < N; i++) {		for (i = 0; i < M; i++) {			int temp = B + A[i][j];			if (temp > 255) {				C[i][j] = 255;			}			else {				C[i][j] = temp;			}		}	}}void substractvalues(int** A, int B, int** C, int N, int M) {
	int i, j, temp;	for (i = 0; i < N; i++) {		for (i = 0; i < M; i++) {			int temp = A[i][j] - B;			if (temp != 0) {				C[i][j] = 255;			}			else {				C[i][j] = temp;			}		}	}}void multiplication(int** A, float** B, int** C, int N)
/* Mengalikan buah citra A dengan matriks koreksi B menjadi citra C.
Citra A, matriks B, dan hasil perkalian C berukuran N  N.
*/
{
	int i, j, k, temp;
	for (i = 0; i <= N - 1; i++)
		for (j = 0; j <= N - 1; j++)
		{
			temp = 0;
			for (k = 0; k <= N - 1; k++)
			{
				temp = temp + A[i][k] * B[k][j];
				/* clipping */
				if (temp < 0)
					C[i][j] = 0;
				else
					if (temp > 255)
						C[i][j] = 255;
					else
						C[i][j] = temp;
			}
		}
}
void multiplication(int** A, float B, int** C, int N)
/* Mengalikan buah citra A dengan matriks koreksi B menjadi citra C.
Citra A, matriks B, dan hasil perkalian C berukuran N  N.
*/
{
	int i, j, temp;
	for (i = 0; i <= N - 1; i++)
		for (j = 0; j <= N - 1; j++)
		{
			temp = A[i][j] * B;
			if (temp < 0) {
				C[i][j] = 0;
			}
			else {
				if (temp > 255) {
					C[i][j] = 255;
				}
				else {
					C[i][j] = (int)temp;
				}
			}
		}
}

void not_operation(bool** A, bool** B, int N, int M)
/* Membuat citra komplemen dari citra biner A.
Komplemennya disimpan di dalam B. Ukuran citra A
adalah N  M.
*/
{
	int i, j;
	for (i = 0; i <= N - 1; i++)
		for (j = 0; j <= M - 1; j++)
		{
			B[i][j] = !A[i][j];
		}
}

void translation(int** A, int** B, int N, int M, int m, int n)
/* Mentranslasi citra A sejauh m, n menjadi citra B. Ukuran citra N  M. */
{
	int i, j;
	for (i = 0; i <= N - 1; i++) {
		for (j = 0; j <= M - 1; j++)
		{
			B[i + m][j + n] = A[i][j];//NOTDONE
		}
	}
}