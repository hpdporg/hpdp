

macro dtDelta dtNamespace,dtLoc
	namespace dtest
	display "In Macro"
	if .disable = 0
		local isDisabled
		define isDisabled 0
		local nestedLevel
		define nestedLevel dtest
		display "Inside"
		while defined nestedLevel
			display "in while"
			if defined nestedLevel.disable
				if nestedLevel.disable = 1
					display "Val is 1"
					break
				else
					nestedLevel = nestedLevel..
					display "First else"
				end if
				if nestedLevel = dtNamespace
					if nestedLevel.disable = 1
						display "Val is 1 nested"
						break
					else
						display "Val is not 1 nested"
						break
					end if
				end if
			else
				display "Second else"
				break
			end if

		end while

		;if dtNamespace.disable = 0
			
		;end if
	end if
	end namespace
end macro

