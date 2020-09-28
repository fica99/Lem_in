import sys
import enum
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors

class Graph():

	def _create_node(self, line):
		data = line.split()
		return data[0]

	def _create_edge(self, line):
		data = line.split('-')
		if len(data) != 2:
			sys.exit("Invalid edge")
		data[0] = data[0].strip()
		data[1] = data[1].strip()
		return tuple(data)

	def _read_graph(self):
		ants = {}
		for line in sys.stdin:
			line = line.strip()
			if line.startswith("#"):
				if line == "##start":
					start = sys.stdin.readline().strip()
					self.start = self._create_node(start)
					self.G.add_node(self.start)
				elif line == "##end":
					end = sys.stdin.readline().strip()
					self.end = self._create_node(end)
					self.G.add_node(self.end)
			elif line.startswith('L'):
				for num, name in map(lambda a: a[1:].split('-'), line.split(' ')):
					if num not in ants:
						ants[num] = []
					ants[num].append(name)
			elif ' ' in line:
				self.nodes.append(self._create_node(line))
				self.G.add_node(self.nodes[-1])
			elif '-' in line:
				self.G.add_edge(*self._create_edge(line))
		self.paths = self.get_paths(ants)

	def get_paths(self, ants):
		paths = set()
		for value in ants.values():
			paths.add(tuple(value))
		new_paths = []
		for path in paths:
			new_path = []
			tmp = [self.start]
			i = 0
			while i < len(path):
				tmp.append(path[i])
				new_path.append(tuple(tmp))
				tmp = [path[i]]
				i += 1
			new_paths.append(new_path)
		return new_paths

	def __init__(self):
		self.G = nx.Graph()
		self.nodes = []
		line = sys.stdin.readline()
		self._read_graph()
		self._colors = list(mcolors.CSS4_COLORS.values())[10::7]

	def draw(self):
		pos = nx.spring_layout(self.G)
		nx.draw_networkx_nodes(self.G, pos, nodelist=self.nodes, node_size=10)
		nx.draw_networkx_nodes(self.G, pos, nodelist=[self.start], node_size=100,node_color="red")
		nx.draw_networkx_nodes(self.G, pos, nodelist=[self.end], node_size=100,node_color="green")
		nx.draw_networkx_edges(self.G, pos, alpha=0.1)
		for i, path in enumerate(self.paths):
			nx.draw_networkx_edges(self.G, pos, path, width=5, alpha=0.5, edge_color=self._colors[i])
		plt.show()


def main():
	graph = Graph()
	graph.draw()

if __name__ == "__main__":
	main()
