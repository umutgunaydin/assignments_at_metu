def construct_forest(function_def):
    forest = []

    for func_def in function_def:
        tree_list = [func_def[:func_def.find("=")].strip()[0]]
        if func_def.find("*") >= 0:
            tree_maker(forest, tree_list, func_def, "*")
        elif func_def.find("+") >= 0:
            tree_maker(forest, tree_list, func_def, "+")
        elif func_def.find("-") >= 0:
            tree_maker(forest, tree_list, func_def, "-")
        elif func_def.find("^") >= 0:
            tree_maker(forest, tree_list, func_def, "^")

        forest.append(tree_list)

    for eachTree in forest:
        traverse_order(eachTree, forest)

    return forest


def tree_maker(forest, tree_list, func_def, operator):
    tree_list.append(operator)
    if func_def[func_def.find("=") + 1:func_def.find(operator)].find("(") >= 0:
        function_char = func_def[func_def.find("=") + 1:func_def.find(operator)].strip()[0]
        already_exist = False
        for tree in forest:
            if tree[0] == function_char:
                popped_tree = forest.pop(forest.index(tree))
                tree_list.append(popped_tree)
                already_exist = True
                break
        if not already_exist:
            tree_list.append(["?" + function_char])
    else:
        tree_list.append([func_def[func_def.find("=") + 1:func_def.find(operator)].strip()])

    if func_def[func_def.find(operator) + 1:].strip().find("(") >= 0:
        function_char = func_def[func_def.find(operator) + 1:].strip()[0]
        already_exist = False
        for tree in forest:
            if tree[0] == function_char:
                popped_tree = forest.pop(forest.index(tree))
                tree_list.append(popped_tree)
                already_exist = True
                break
        if not already_exist:
            tree_list.append(["?" + function_char])
    else:
        tree_list.append([func_def[func_def.find(operator) + 1:].strip()])

    return tree_list


def traverse_order(eachTree, forest):
    if len(eachTree) == 4:
        traverse_order(eachTree[2], forest)
        traverse_order(eachTree[3], forest)
    elif eachTree[0].startswith("?"):
        for each in forest:
            if each[0] == eachTree[0][1]:
                popped = forest.pop(forest.index(each))
                traverse_order(popped, forest)
                eachTree.clear()
                for each_element in popped:
                    eachTree.append(each_element)
                return
