class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        r=moves.count('R')
        l=moves.count("L")
        dash=moves.count("_")

        return max(l,r)+dash-min(l,r)