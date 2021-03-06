

def GAFF(pr_1, pr_2):
	score_dict = {}
	with open('/home/lab2/BLOSUM62.txt') as mat:
		for ind,line in enumerate(mat):
			if ind == 0:
				aa = line.strip(' \n').split('  ')
				ind_dict = dict(zip(range(len(aa)),aa))
			else:
				mat_score = filter(lambda i: i != '',line[1:].strip(' \n').split(' '))
				for col, ite in enumerate(mat_score):
					score_dict[ind_dict[ind-1]+ind_dict[col]] = int(ite)
	n_rows = len(pr_1) + 1
	n_columns = len(pr_2) + 1
	score_mat = [[float('-inf') for i in xrange(n_columns)] for j in xrange(n_rows)]	
	track_mat = [[0 for i in xrange(n_columns)] for j in xrange(n_rows)]
	track_mat_hor = [[0 for i in xrange(n_columns)] for j in xrange(n_rows)]
	track_mat_lon = [[0 for i in xrange(n_columns)] for j in xrange(n_rows)]
	
	score_mat_lon = [[float('-inf') for i in xrange(n_columns)] for j in xrange(n_rows)]
	score_mat_hor = [[float('-inf') for i in xrange(n_columns)] for j in xrange(n_rows)]
	score_mat[0][0] = 0
	score_mat_hor[0][0] = 0
	score_mat_lon[0][0] = 0
	for i in xrange(1,n_rows):
		score_mat_lon[i][0] = -11 - (i-1) * 1
		track_mat_lon[i][0] = 'from dia up'
		track_mat[i][0] = 'from lon'
		score_mat_hor[i][0] = float('-inf')
	for i in xrange(1,n_columns):
		score_mat[0][i] = -11 - (i-1) * 1
		track_mat_hor[0][i] = 'from dia left'
		score_mat_lon[0][i] = float('-inf')
		track_mat[0][i] = 'from hor'
	for i in xrange(n_rows-1):
		for j in xrange(n_columns-1):
			if score_mat[i+1][j] - 11 >= score_mat_hor[i+1][j] - 1:
				score_mat_hor[i+1][j+1] = score_mat[i+1][j] - 11
				track_mat_hor[i+1][j+1] = 'from dia left'
			else:
				score_mat_hor[i+1][j+1] = score_mat_hor[i+1][j] - 1
				track_mat_hor[i+1][j+1] = 'from left'
			if score_mat[i][j+1] - 11 >= score_mat_lon[i][j+1] - 1:
				score_mat_lon[i+1][j+1] = score_mat[i][j+1] - 11
				track_mat_lon[i+1][j+1] = 'from dia up'
			else:
				score_mat_lon[i+1][j+1] = score_mat_lon[i][j+1] - 1
				track_mat_lon[i+1][j+1] = 'from up'
			score_mat[i+1][j+1] = max(score_mat[i][j]+ score_dict[pr_1[i]+pr_2[j]],score_mat_hor[i+1][j+1],score_mat_lon[i+1][j+1])
			if score_mat[i+1][j+1] == score_mat[i][j]+ score_dict[pr_1[i]+pr_2[j]]:
				track_mat[i+1][j+1] = 'from up left'
			elif score_mat[i+1][j+1] == score_mat_hor[i+1][j+1]:
				track_mat[i+1][j+1] = 'from hor'
			else:
				track_mat[i+1][j+1] = 'from lon'
	row = n_rows - 1
	col = n_columns -1
	s = '' 
	t = ''
	while col != 0 or row != 0:
		if track_mat[row][col] == 'from up left':
			s = pr_1[row-1] + s
			t = pr_2[col-1] + t
			row -= 1
			col -= 1
		elif track_mat[row][col] == 'from hor':
			while track_mat_hor[row][col] != 'from dia left':
				s = '-' + s
				t = pr_2[col-1] + t
				col -= 1
			s = '-' + s
			t = pr_2[col-1] + t
			col -= 1
		elif track_mat[row][col] == 'from lon':
			while track_mat_lon[row][col] != 'from dia up':
				s = pr_1[row-1] + s
				t = '-' + t
				row -= 1
			s = pr_1[row-1] + s
			t = '-' + t
			row -= 1
			
	return score_mat[n_rows-1][n_columns-1], s, t



if __name__ == '__main__':
    from FASTA import FASTA
    fasta = FASTA('/home/lab2/input/f.txt')
    seqs = fasta.sequences()
    result = GAFF(seqs[0],seqs[1])
    print('\n'.join(map(str,result)))