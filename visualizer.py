import sys
import networkx as nx

class Graph():
	def _create_node(self, line):
		data = line.split()
		if len(data) != 3:
			sys.exit("Invalid node")
		if data[1].isdigit() != True or data[2].isdigit() != True:
			sys.exit("Node coordinates must be integers")
		return tuple(data)

	def _read_input(self):
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
				self.nodes.append(self._create_node(line))
			elif '-' in line:

			elif len(line) == 0:
				break

		def _read_output_data(self):

	def __init__(self):
		self.G = nx.Graph()
		self.start = None
		self.end = None
		self.nodes = []
		self._read_input_data()
		self._read_output_data()

