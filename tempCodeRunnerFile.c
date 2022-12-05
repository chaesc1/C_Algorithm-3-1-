    if(findMapPath(x+1, y) || findMapPath(x, y+1) || findMapPath(x-1, y) || findMapPath(x, y-1))
                {
                    return true;
                }
                map[x][y] = BLOCKED;
            return false;