import sys
import enum
import networkx as nx

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
		data[1] = int(data[1])
		data[2] = int(data[2])
		return tuple(data)

	def _create_edge(self, line):
		data = line.split('-')
		if len(data) != 2:
			sys.exit("Invalid edge")
		data[0] = data[0].strip()
		data[1] = data[1].strip()
		return tuple(data)

	def _read_input(self):
		line = sys.stdin.readline()
		line = line.strip()
		if line.isdigit() != True:
			sys.exit("Expected number as number of ants")
		self.nb_ants = int(line)
		type_input = self._InputType.Nodes
		for line in sys.stdin:
			line = line.strip()
			if line.startswith("#"):
				if line == "##start":
					start = sys.stdin.readline()
					self.start = self._create_node(start)
				elif line == "##end":
					end = sys.stdin.readline()
					self.end = self._create_node(end)
			elif ' ' in line:
				if type_input == self._InputType.Nodes:
					self.nodes.append(self._create_node(line))
				else:
					sys.exit("Expected nodes data")
			elif '-' in line:
				self.edges.append(self._create_edge(line))
				type_input = self._InputType.Edges
			elif len(line) == 0:
				break
			else:
				sys.exit("Incorrect input")

	def _read_output(self):
		pass
	
	def __init__(self):
		self.G = nx.Graph()
		self.start = None
		self.end = None
		self.nodes = []
		self.edges = []
		self._read_input()
		if len(self.nodes) == 0:
			sys.exit("No nodes in graph")
		if len(self.edges) == 0:
			sys.exit("No edges in graph")
		if self.start == None:
			sys.exit("No start node")
		if self.end == None:
			sys.exit("No end node")
		self._read_output()

def main():
	graph = Graph()

if __name__ == "__main__":
	main()
