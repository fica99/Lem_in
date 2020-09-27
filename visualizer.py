import sys
import enum
import networkx as nx
import matplotlib.pyplot as plt

class Graph():

	class _InputType(enum.Enum):
		Nodes = 1
		Edges = 2

	def _create_node(self, line):
		data = line.split()
		if len(data) != 3:
			sys.exit("Invalid node")
		if data[1].isdigit() != True or data[2].isdigit() != True:
			sys.exit("Node coordinates must be integers")
		return data[0]

	def _create_edge(self, line):
		data = line.split('-')
		if len(data) != 2:
			sys.exit("Invalid edge")
		data[0] = data[0].strip()
		data[1] = data[1].strip()
		return tuple(data)

	def _read_graph(self):
		type_input = self._InputType.Nodes
		for line in sys.stdin:
			line = line.strip()
			if line.startswith("#"):
				if line == "##start":
					start = sys.stdin.readline()
					self.start = self._create_node(start)
					self.G.add_node(self.start)
				elif line == "##end":
					end = sys.stdin.readline()
					self.end = self._create_node(end)
					self.G.add_node(self.end)
			elif ' ' in line:
				if type_input == self._InputType.Nodes:
					self.nodes.append(self._create_node(line))
					self.G.add_node(self.nodes[-1])
				else:
					sys.exit("Expected nodes data")
			elif '-' in line:
				self.G.add_edge(*self._create_edge(line))
				type_input = self._InputType.Edges
			elif len(line) == 0:
				break
			else:
				sys.exit("Incorrect input")

	def _read_output(self):
		pass

	def __init__(self):
		self.G = nx.Graph()
		self.end = None
		self.start = None
		self.nodes = []
		line = sys.stdin.readline()
		line = line.strip()
		if line.isdigit() != True:
			sys.exit("Expected number as number of ants")
		self._read_graph()
		if len(self.nodes) == 0:
			sys.exit("No nodes in graph")
		if self.start == None:
			sys.exit("No start node")
		if self.end == None:
			sys.exit("No end node")
		self._read_output()

	def draw(self):
		pos = nx.spring_layout(self.G)
		nx.draw_networkx_nodes(self.G, pos, nodelist=self.nodes, node_size=50)
		nx.draw_networkx_nodes(self.G, pos, nodelist=[self.start], node_size=100,node_color="red")
		nx.draw_networkx_nodes(self.G, pos, nodelist=[self.end], node_size=100,node_color="green")
		nx.draw_networkx_edges(self.G, pos)
		plt.show()


def main():
	graph = Graph()
	graph.draw()

if __name__ == "__main__":
	main()
