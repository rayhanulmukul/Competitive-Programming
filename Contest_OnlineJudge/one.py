def verticalSum(self, root):
    if root == None:
        return 0
    q = deque([(root, 0)])
    d = defaultdict(list)

    while q:
        node, level = q.popleft()
        d[level].append(node.data)

        if node.left != None:
            q.append((node.left, level - 1))
        if node.right != None:
            q.append((node.right, level + 1))
        
    ans = []

    for key, val in sorted(d.items()):
        ans.append(sum(val))

    return ans;